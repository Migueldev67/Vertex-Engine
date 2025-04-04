/*
* Copyright (c) 2022-2023 NVIDIA CORPORATION. All rights reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/ 

#pragma once

#include <atomic>

#include "d3d12.h"

namespace sl
{
namespace interposer
{
struct DECLSPEC_UUID("10B90151-4435-4004-9FAD-19361488899A") D3D12Device : ID3D12Device10
{
    D3D12Device(ID3D12Device * original);

    D3D12Device(const D3D12Device&) = delete;
    D3D12Device& operator=(const D3D12Device&) = delete;

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj) override final;
    ULONG   STDMETHODCALLTYPE AddRef() override final;
    ULONG   STDMETHODCALLTYPE Release() override final;

#pragma region ID3D12Object
    HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID guid, UINT * pDataSize, void* pData) override final;
    HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID guid, UINT DataSize, const void* pData) override final;
    HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(REFGUID guid, const IUnknown * pData) override final;
    HRESULT STDMETHODCALLTYPE SetName(LPCWSTR Name) override final;
#pragma endregion
#pragma region ID3D12Device
    UINT    STDMETHODCALLTYPE GetNodeCount() override final;
    HRESULT STDMETHODCALLTYPE CreateCommandQueue(const D3D12_COMMAND_QUEUE_DESC * pDesc, REFIID riid, void** ppCommandQueue) override final;
    HRESULT STDMETHODCALLTYPE CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE type, REFIID riid, void** ppCommandAllocator) override final;
    HRESULT STDMETHODCALLTYPE CreateGraphicsPipelineState(const D3D12_GRAPHICS_PIPELINE_STATE_DESC * pDesc, REFIID riid, void** ppPipelineState) override final;
    HRESULT STDMETHODCALLTYPE CreateComputePipelineState(const D3D12_COMPUTE_PIPELINE_STATE_DESC * pDesc, REFIID riid, void** ppPipelineState) override final;
    HRESULT STDMETHODCALLTYPE CreateCommandList(UINT nodeMask, D3D12_COMMAND_LIST_TYPE type, ID3D12CommandAllocator * pCommandAllocator, ID3D12PipelineState * pInitialState, REFIID riid, void** ppCommandList) override final;
    HRESULT STDMETHODCALLTYPE CheckFeatureSupport(D3D12_FEATURE Feature, void* pFeatureSupportData, UINT FeatureSupportDataSize) override final;
    HRESULT STDMETHODCALLTYPE CreateDescriptorHeap(const D3D12_DESCRIPTOR_HEAP_DESC * pDescriptorHeapDesc, REFIID riid, void** ppvHeap) override final;
    UINT    STDMETHODCALLTYPE GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType) override final;
    HRESULT STDMETHODCALLTYPE CreateRootSignature(UINT nodeMask, const void* pBlobWithRootSignature, SIZE_T blobLengthInBytes, REFIID riid, void** ppvRootSignature) override final;
    void    STDMETHODCALLTYPE CreateConstantBufferView(const D3D12_CONSTANT_BUFFER_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE CreateShaderResourceView(ID3D12Resource * pResource, const D3D12_SHADER_RESOURCE_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE CreateUnorderedAccessView(ID3D12Resource * pResource, ID3D12Resource * pCounterResource, const D3D12_UNORDERED_ACCESS_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE CreateRenderTargetView(ID3D12Resource * pResource, const D3D12_RENDER_TARGET_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE CreateDepthStencilView(ID3D12Resource * pResource, const D3D12_DEPTH_STENCIL_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE CreateSampler(const D3D12_SAMPLER_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE CopyDescriptors(UINT NumDestDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE * pDestDescriptorRangeStarts, const UINT * pDestDescriptorRangeSizes, UINT NumSrcDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE * pSrcDescriptorRangeStarts, const UINT * pSrcDescriptorRangeSizes, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType) override final;
    void    STDMETHODCALLTYPE CopyDescriptorsSimple(UINT NumDescriptors, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart, D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType) override final;
    D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC * pResourceDescs) override final;
    D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE GetCustomHeapProperties(UINT nodeMask, D3D12_HEAP_TYPE heapType) override final;
    HRESULT STDMETHODCALLTYPE CreateCommittedResource(const D3D12_HEAP_PROPERTIES * pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC * pResourceDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, REFIID riidResource, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreateHeap(const D3D12_HEAP_DESC * pDesc, REFIID riid, void** ppvHeap) override final;
    HRESULT STDMETHODCALLTYPE CreatePlacedResource(ID3D12Heap * pHeap, UINT64 HeapOffset, const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, REFIID riid, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreateReservedResource(const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, REFIID riid, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreateSharedHandle(ID3D12DeviceChild * pObject, const SECURITY_ATTRIBUTES * pAttributes, DWORD Access, LPCWSTR Name, HANDLE * pHandle) override final;
    HRESULT STDMETHODCALLTYPE OpenSharedHandle(HANDLE NTHandle, REFIID riid, void** ppvObj) override final;
    HRESULT STDMETHODCALLTYPE OpenSharedHandleByName(LPCWSTR Name, DWORD Access, HANDLE * pNTHandle) override final;
    HRESULT STDMETHODCALLTYPE MakeResident(UINT NumObjects, ID3D12Pageable* const* ppObjects) override final;
    HRESULT STDMETHODCALLTYPE Evict(UINT NumObjects, ID3D12Pageable* const* ppObjects) override final;
    HRESULT STDMETHODCALLTYPE CreateFence(UINT64 InitialValue, D3D12_FENCE_FLAGS Flags, REFIID riid, void** ppFence) override final;
    HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason() override final;
    void    STDMETHODCALLTYPE GetCopyableFootprints(const D3D12_RESOURCE_DESC * pResourceDesc, UINT FirstSubresource, UINT NumSubresources, UINT64 BaseOffset, D3D12_PLACED_SUBRESOURCE_FOOTPRINT * pLayouts, UINT * pNumRows, UINT64 * pRowSizeInBytes, UINT64 * pTotalBytes) override final;
    HRESULT STDMETHODCALLTYPE CreateQueryHeap(const D3D12_QUERY_HEAP_DESC * pDesc, REFIID riid, void** ppvHeap) override final;
    HRESULT STDMETHODCALLTYPE SetStablePowerState(BOOL Enable) override final;
    HRESULT STDMETHODCALLTYPE CreateCommandSignature(const D3D12_COMMAND_SIGNATURE_DESC * pDesc, ID3D12RootSignature * pRootSignature, REFIID riid, void** ppvCommandSignature) override final;
    void    STDMETHODCALLTYPE GetResourceTiling(ID3D12Resource * pTiledResource, UINT * pNumTilesForEntireResource, D3D12_PACKED_MIP_INFO * pPackedMipDesc, D3D12_TILE_SHAPE * pStandardTileShapeForNonPackedMips, UINT * pNumSubresourceTilings, UINT FirstSubresourceTilingToGet, D3D12_SUBRESOURCE_TILING * pSubresourceTilingsForNonPackedMips) override final;
    LUID    STDMETHODCALLTYPE GetAdapterLuid() override final;
#pragma endregion
#pragma region ID3D12Device1
    HRESULT STDMETHODCALLTYPE CreatePipelineLibrary(const void* pLibraryBlob, SIZE_T BlobLength, REFIID riid, void** ppPipelineLibrary) override final;
    HRESULT STDMETHODCALLTYPE SetEventOnMultipleFenceCompletion(ID3D12Fence* const* ppFences, const UINT64 * pFenceValues, UINT NumFences, D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags, HANDLE hEvent) override final;
    HRESULT STDMETHODCALLTYPE SetResidencyPriority(UINT NumObjects, ID3D12Pageable* const* ppObjects, const D3D12_RESIDENCY_PRIORITY * pPriorities) override final;
#pragma endregion
#pragma region ID3D12Device2
    HRESULT STDMETHODCALLTYPE CreatePipelineState(const D3D12_PIPELINE_STATE_STREAM_DESC * pDesc, REFIID riid, void** ppPipelineState) override final;
#pragma endregion
#pragma region ID3D12Device3
    HRESULT STDMETHODCALLTYPE OpenExistingHeapFromAddress(const void* pAddress, REFIID riid, void** ppvHeap) override final;
    HRESULT STDMETHODCALLTYPE OpenExistingHeapFromFileMapping(HANDLE hFileMapping, REFIID riid, void** ppvHeap) override final;
    HRESULT STDMETHODCALLTYPE EnqueueMakeResident(D3D12_RESIDENCY_FLAGS Flags, UINT NumObjects, ID3D12Pageable* const* ppObjects, ID3D12Fence * pFenceToSignal, UINT64 FenceValueToSignal) override final;
#pragma endregion
#pragma region ID3D12Device4
    HRESULT STDMETHODCALLTYPE CreateCommandList1(UINT NodeMask, D3D12_COMMAND_LIST_TYPE Type, D3D12_COMMAND_LIST_FLAGS Flags, REFIID riid, void** ppCommandList) override final;
    HRESULT STDMETHODCALLTYPE CreateProtectedResourceSession(const D3D12_PROTECTED_RESOURCE_SESSION_DESC * pDesc, REFIID riid, void** ppSession) override final;
    HRESULT STDMETHODCALLTYPE CreateCommittedResource1(const D3D12_HEAP_PROPERTIES * pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, ID3D12ProtectedResourceSession * pProtectedSession, REFIID riidResource, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreateHeap1(const D3D12_HEAP_DESC * pDesc, ID3D12ProtectedResourceSession * pProtectedSession, REFIID riid, void** ppvHeap) override final;
    HRESULT STDMETHODCALLTYPE CreateReservedResource1(const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, ID3D12ProtectedResourceSession * pProtectedSession, REFIID riid, void** ppvResource) override final;
    D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo1(UINT VisibleMask, UINT NumResourceDescs, const D3D12_RESOURCE_DESC * pResourceDescs, D3D12_RESOURCE_ALLOCATION_INFO1 * pResourceAllocationInfo1) override final;
#pragma endregion
#pragma region ID3D12Device5
    HRESULT STDMETHODCALLTYPE CreateLifetimeTracker(ID3D12LifetimeOwner * pOwner, REFIID riid, void** ppvTracker) override final;
    void    STDMETHODCALLTYPE RemoveDevice() override final;
    HRESULT STDMETHODCALLTYPE EnumerateMetaCommands(UINT * pNumMetaCommands, D3D12_META_COMMAND_DESC * pDescs) override final;
    HRESULT STDMETHODCALLTYPE EnumerateMetaCommandParameters(REFGUID CommandId, D3D12_META_COMMAND_PARAMETER_STAGE Stage, UINT * pTotalStructureSizeInBytes, UINT * pParameterCount, D3D12_META_COMMAND_PARAMETER_DESC * pParameterDescs) override final;
    HRESULT STDMETHODCALLTYPE CreateMetaCommand(REFGUID CommandId, UINT NodeMask, const void* pCreationParametersData, SIZE_T CreationParametersDataSizeInBytes, REFIID riid, void** ppMetaCommand) override final;
    HRESULT STDMETHODCALLTYPE CreateStateObject(const D3D12_STATE_OBJECT_DESC * pDesc, REFIID riid, void** ppStateObject) override final;
    void    STDMETHODCALLTYPE GetRaytracingAccelerationStructurePrebuildInfo(const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS * pDesc, D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO * pInfo) override final;
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS STDMETHODCALLTYPE CheckDriverMatchingIdentifier(D3D12_SERIALIZED_DATA_TYPE SerializedDataType, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER * pIdentifierToCheck) override final;
#pragma endregion
#pragma region ID3D12Device6
    HRESULT STDMETHODCALLTYPE SetBackgroundProcessingMode(D3D12_BACKGROUND_PROCESSING_MODE Mode, D3D12_MEASUREMENTS_ACTION MeasurementsAction, HANDLE hEventToSignalUponCompletion, BOOL * pbFurtherMeasurementsDesired) override final;
#pragma endregion
#pragma region ID3D12Device7
    HRESULT STDMETHODCALLTYPE AddToStateObject(const D3D12_STATE_OBJECT_DESC * pAddition, ID3D12StateObject * pStateObjectToGrowFrom, REFIID riid, void** ppNewStateObject) override final;
    HRESULT STDMETHODCALLTYPE CreateProtectedResourceSession1(const D3D12_PROTECTED_RESOURCE_SESSION_DESC1 * pDesc, REFIID riid, void** ppSession) override final;
#pragma endregion
#pragma region ID3D12Device8
    D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo2(UINT visibleMask, UINT numResourceDescs, const D3D12_RESOURCE_DESC1 * pResourceDescs, D3D12_RESOURCE_ALLOCATION_INFO1 * pResourceAllocationInfo1) override final;
    HRESULT STDMETHODCALLTYPE CreateCommittedResource2(const D3D12_HEAP_PROPERTIES * pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC1 * pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, ID3D12ProtectedResourceSession * pProtectedSession, REFIID riidResource, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreatePlacedResource1(ID3D12Heap * pHeap, UINT64 HeapOffset, const D3D12_RESOURCE_DESC1 * pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, REFIID riid, void** ppvResource) override final;
    void    STDMETHODCALLTYPE CreateSamplerFeedbackUnorderedAccessView(ID3D12Resource * pTargetedResource, ID3D12Resource * pFeedbackResource, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor) override final;
    void    STDMETHODCALLTYPE GetCopyableFootprints1(const D3D12_RESOURCE_DESC1 * pResourceDesc, UINT FirstSubresource, UINT NumSubresources, UINT64 BaseOffset, D3D12_PLACED_SUBRESOURCE_FOOTPRINT * pLayouts, UINT * pNumRows, UINT64 * pRowSizeInBytes, UINT64 * pTotalBytes) override final;
#pragma endregion
#pragma region ID3D12Device9
    HRESULT STDMETHODCALLTYPE CreateShaderCacheSession(const D3D12_SHADER_CACHE_SESSION_DESC * pDesc, REFIID riid, void** ppvSession) override final;
    HRESULT STDMETHODCALLTYPE ShaderCacheControl(D3D12_SHADER_CACHE_KIND_FLAGS Kinds, D3D12_SHADER_CACHE_CONTROL_FLAGS Control) override final;
    HRESULT STDMETHODCALLTYPE CreateCommandQueue1(const D3D12_COMMAND_QUEUE_DESC * pDesc, REFIID CreatorID, REFIID riid, void** ppCommandQueue) override final;
#pragma endregion
#pragma region ID3D12Device10
    HRESULT STDMETHODCALLTYPE CreateCommittedResource3(const D3D12_HEAP_PROPERTIES* pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC1* pDesc, D3D12_BARRIER_LAYOUT InitialLayout, const D3D12_CLEAR_VALUE* pOptimizedClearValue, ID3D12ProtectedResourceSession* pProtectedSession, UINT32 NumCastableFormats, DXGI_FORMAT* pCastableFormats, REFIID riidResource, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreatePlacedResource2(ID3D12Heap* pHeap, UINT64 HeapOffset, const D3D12_RESOURCE_DESC1* pDesc, D3D12_BARRIER_LAYOUT InitialLayout, const D3D12_CLEAR_VALUE* pOptimizedClearValue, UINT32 NumCastableFormats, DXGI_FORMAT* pCastableFormats, REFIID riid, void** ppvResource) override final;
    HRESULT STDMETHODCALLTYPE CreateReservedResource2(const D3D12_RESOURCE_DESC* pDesc, D3D12_BARRIER_LAYOUT InitialLayout, const D3D12_CLEAR_VALUE* pOptimizedClearValue, ID3D12ProtectedResourceSession* pProtectedSession, UINT32 NumCastableFormats, DXGI_FORMAT* pCastableFormats, REFIID riid, void** ppvResource) override final;
#pragma endregion

    uint8_t padding[8];
    ID3D12Device* m_base; // IMPORTANT: Must be at a fixed offset to support tools, do not move!

    bool checkAndUpgradeInterface(REFIID riid);

    std::atomic<LONG> m_refCount = 1;
    uint32_t m_interfaceVersion{};
};
}
}
